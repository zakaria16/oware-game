# Oware Game

[![Build and Run Test](https://github.com/zakaria16/oware-game/actions/workflows/cmake.yml/badge.svg)](https://github.com/zakaria16/oware-game/actions/workflows/cmake.yml)

Implementation of [Oware game](https://en.wikipedia.org/wiki/Oware) in c++

Fully implemented [Abapa](http://www.oware.org/abapa.asp) version of oware

To add a different game with it set of rules extend `OwareAbstractClass` and implement the virtual methods.
After that, you can load your version of the game like this
```c++
  oware::Game game{std::make_unique<YourDerivedClass>()};
  game.start("player1", "player2");
```

- See `Oware` class for the Aba ba implementation in [Oware.hpp](./src/Oware.hpp) and [Oware.cpp](./src/Oware.hpp)
- See  [main.cpp](./src/main.cpp) for console example of oware game
  to add a new gm
# Build

```shell
  mkdir build
  cd build
  cmake ..
  make
```

## test
to run the tests
```c++
 mkdir build
  cd build
  cmake ..
  make test
  ./test/test
```

## TODO

| Date      | To be done                                           | fixed |
|-----------|------------------------------------------------------|-------|
| 14-dec-22 | ~~for oware::move if seed present is zero dont sow~~ | yes   |
|           | add networking                                       |       |
|           | add GUI                                              |       |
