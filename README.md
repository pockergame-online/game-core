# Game Core

[![Build Status](https://travis-ci.org/pockergame-online/game-core.svg?branch=master)](https://travis-ci.org/pockergame-online/game-core)

Game Core is library built on C++ that has all the functionality related with the poker game, this library counts with:

  - Card class representation
  - Deck class representation
  - operators related with the classes to make easy the instance operations

# At this moment is on construction

  

## Installation

Game Core requires [C++](http://www.cplusplus.com/forum/general/19426/) compiler.

### Installation on Mac
Install counts with Makefile to this platform to generate a dynamic library

```sh
$ make clean #to clean all the object code
$ make all #to generate a new dynamic library
$ make test_game #to compile a test library client
$ ./test_game #to test the library program
```

### Plugins

| Plugin | README |
| ------ | ------ |
| GitHub | [plugins/github/README.md][PlGh] |
