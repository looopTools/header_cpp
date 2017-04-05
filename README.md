# header_cpp
A lightweight C++ library for writing and reading data/file headers

The goal for is to make header_cpp your favourite tool for reading and writing headers in C++. We aim to keep up todate with the latest standardised C++ version. From C++17 and on we will also further ensure that the previous version is still supported.

## Documentation

To be determined

## Build

Header\_cpp utilise waf [[1]](https://waf.io) as build system, with modification provided by Steinwurf Aps [[2]](http://steinwurf.com), whom provided the modified waf on github
[[3]](https://github.com/steinwurf/waf)[[4]](https://github.com/steinwurf/waf-tools). However, with header\_cpp we distributed the waf binary and you need to do nothing additional.

For building header\_cpp change directory to the root folder of the project and run the following commands

   python waf configure
   python waf build

The resulting files should be placed in the resulting build folder.

# Feature Request or Bug Registration

If you find a feature missing or a header we have missed, or if you simply find a bug. Please use
the issue tracker, instead of contacting a team directly.

## Developers

- __Lars Nielsen - Maintainer__
- __Andreas Reng Mogensen - Developer__


## Resource:

1. [waf - waf.io](https://waf.io)
2. [Steinwurf Aps - steinwurf.com](http://steinwurf.com)
3. [steinwurf/waf - github.com/steinwurf/waf](https://github.com/steinwurf/waf)
4. [steinwurf/waf-tools - github.com/steinwurf/waf-tools](https://github.com/steinwurf/waf-tools)
