# BlockWorld
Block World development moved to a new repo on Linux.

The current goal is to get development on Block World so that non-Windows friends can also try it out, and make some deep revisions to the original program structure for long-term sustainability.

## How To Build
1. Make a new directory and cd into the new directory.
   ```bash
   > mkdir BlockWorld && cd BlockWorld
   ```
2. Clone the repository inside the folder.
   ```bash
   > git clone https://github.com/AJQuattropani/block-world-linux.git
   ```
3. Make and move into a build directory, and build project. For building at the same location as the repo:
   ```bash
   > mkdir build && cd build
   > cmake ../block-world-linux
   > cmake --build .
   ```
4. Run the output executable. You should get a window.
   ```bash
   > ./BlockWorld
   ```
