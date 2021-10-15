// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#import <cstdio>
#import <generator>
#import <optional>
#import <vector>

using namespace std;

generator<int> g0() {}

generator<int> g1() {
    co_yield 9;
}

generator<int> g2() {
    co_yield 9;
    co_yield 8;
}

generator<int> g3() {
    throw 42;
}

generator<int> g4() {
    co_yield 1;
    throw 42;
}

void dump(char const* const name, const vector<int>& v, const optional<int> e) {
    printf("%s: (", name);
    for (auto const& elem : v) {
        printf(" %d", elem);
    }
    if (e.has_value()) {
        printf(") except(%d)", *e);
    } else {
        printf(") noexcept");
    }
}

bool test_gen(char const* name, generator<int> g, const vector<int>& v, optional<int> e) {
    vector<int> r;
    optional<int> re;

    try {
        r.insert(r.end(), g.begin(), g.end());
    } catch (int evalue) {
        re = evalue;
    }
    if (re == e && r == v) {
        return true;
    }

    printf("unexpected result: ");
    dump(name, r, re);
    dump(" , expected", v, e);
    putchar('\n');
    return false;
}

bool test_all() {
    bool success = true;

    success = test_gen("g0", g0(), {}, nullopt) && success;
    success = test_gen("g1", g1(), {9}, nullopt) && success;
    success = test_gen("g2", g2(), {9, 8}, nullopt) && success;
    success = test_gen("g3", g3(), {}, 42) && success;
    success = test_gen("g4", g4(), {1}, 42) && success;

    return success;
}

int main() {
    const bool success = test_all();
    puts(success ? "pass" : "fail");
    return !success;
}
