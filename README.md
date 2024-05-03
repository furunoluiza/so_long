# so_long
Welcome to the repository of "so_long" project for 42 School!

<img src="https://github.com/furunoluiza/so_long/blob/main/textures/print/Screenshot%20from%202024-04-30%2018-42-11.png">
</div>

## Project Description
This is a graphic project to create a 2D game developed in C using the MinilibX graphic library. The game consists of a maze where the player must collect all collectible items (C) and reach the exit (E) to win.

## How to Use

1. Install

```sh
git@github.com:furunoluiza/so_long.git
```
2. Enter the directory
   
```bash
cd so_long
```

3. Install MinilibX library in the "libs" directory
   
```
cd libs && git@github.com:42Paris/minilibx-linux.git minilibx && cd ..
```

4. Compilation
   
```bash
make
```

5. Execute
   
```bash
./so_long maps/map.ber
```

The game is initiated by a map file in the ```.ber``` format containing only the following valid characters:

- E = _exit_ = royal victory
- P = _player_ = frog
- C = _collectibles_ = dragon-fly
- 1 = _walls_ = water
- 0 = _floor_ = rocks
