This directory contains the subset of Boost 1.73.0 sources necessary for the [Boost.Math][] library extracted with
Boost's [bcp][] tool into the top-level namespace `_Boost`.

Update procedure (from a Native Tools Command Prompt):
1. We'll use the metasyntactic variable name `%STL%` to refer to the path of the STL repository.
1. Remove the previous Boost extract from the STL repo: `rd/s/q %STL%\3rdparty\BoostMath`
1. Restore this file: `git restore %STL%\3rdparty\BoostMath\README.md`
1. Checkout a full Boost repository somewhere; we'll use `%BOOST%` to name the path to that repository.
1. Navigate to the Boost repo: `cd %BOOST%`
1. Minimally configure Boost and build `bcp`: `bootstrap.bat && b2 headers && b2 tools\bcp`
1. Use `bcp` to extract the Math library into the STL repo:
   `dist\bin\bcp --namespace=_Boost math %STL%\3rdparty\BoostMath`
1. If necessary, update the Boost versions mentioned in this file - both at the top, and in the embedded links below.

[bcp]: https://www.boost.org/doc/libs/1_73_0/tools/bcp/doc/html/index.html
[Boost.Math]: https://www.boost.org/doc/libs/1_73_0/libs/math/doc/html/index.html
