<h1 align="center">
	So Long
</h1>

## 🕹️ General information
Version: 2.3. Bonus included.</br>
A complete and straightforward implementation of So Long 42 project.</br>
I use the [/MLX42 library](https://github.com/codam-coding-college/MLX42) fot many reasons detailed in its docs.</br>
Efforts have been made to compartmentalize the code into functional parts: the program (/so_long), the maps management, graphics (tiles, animations, facade for graphic library), events (keypress and game logic).</br>

## 🚀 Set-up
To keep the GitHub repository tidy and to avoid displaying library code, the `lib` directory is archived. Follow the steps below to set up and run the project:
1. **Decompress the Libraries**: `tar xzf lib.tar.gz && rm -rf lib.tar.gz`</br>
If needed, to re-archive : `tar czf lib.tar.gz lib/ && rm -rf lib/`
2. **Compile the Project**: `make bonus`</br>
Note: The initial compilation can take a bit longer due to libraries.
3. **Launch the Game**:
`./so_long_bonus assets/maps/classic_bonus.ber`

## 🎛️ Features
- 12-frame animations for movements in all four directions.
- A move counter displayed below the game scene.
- Implementation of static enemy patrols.
- End-game screens for both victory ("You win") and defeat ("Game Over").
- Dynamic tile sizing based on map dimensions.
- Can parse any size of map, but large maps that cannot be displayed adequately (e.g., 420x190) will trigger a `Map is too large for display` error. The parsing can be seen by including a invalid block in the same map: the `Invalid block` error will be properly raised (because parsing is done before displaying).

## 🛠️ Implementation details
- The bonus and mandatory components were developed concurrently. To complies with 42 correction rules, `make bonus` compile the same code except two line that recognize the enemy block as legit. It output the executable `./so_long_bonus`.
- Every allocated pointer is checked and stored by `track_allocation()`. In case of error, the allocated pointer list is freed and the game is stopped.
- To enhance code clarity, a [facade pattern](https://refactoring.guru/design-patterns/facade) is employed when interfacing with MLX42.

## 📋 Testing
Tested by 42 students (125%) and mention as an outstanding project 🎉. 

## ✨ Illustrations
<img width="1648" alt="classic_bonus" src="https://github.com/ulyssegerkens/so_long/assets/99326326/f6c02a1b-eb9b-45b5-a989-c05ccb4dd1b8">
<img width="1792" alt="bigest" src="https://github.com/ulyssegerkens/so_long/assets/99326326/a0b0faa2-349b-469b-b3a4-746c3e9f19b2">
<img width="1813" alt="game_over" src="https://github.com/ulyssegerkens/so_long/assets/99326326/551fbc9f-5567-4d6b-99ff-0d39561dba12">
