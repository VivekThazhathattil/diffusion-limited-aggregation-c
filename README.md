# Diffusion Limited Aggregation in C

Diffusion Limited Aggregation test with C. ASCII display.

## Instructions

* Clone the repo

* `cd` into the working directory

* Give execution permission to `run.sh`  with `chmod +x run.sh`

* Use `./run.sh` to create the executable

* Run the executable with `./main`

## Notes:

* Adjust wind with `-w` flag. It can take the values 0, 1, or 2, corresponding to no wind, breeze and strong winds respectively.

### Example-1: `./main -w 0` will create something similar to this:

https://user-images.githubusercontent.com/63693789/230949925-ee93bfbd-0334-4f98-9528-c982b37376c4.mp4

### Example-2: `./main -w 2` will create something similar to this:

https://user-images.githubusercontent.com/63693789/231085285-23cd60cb-274d-4a00-ae28-0a75a2fa1c42.mp4

* Randomize wind direction and magnitude with `-r` flag (1 to randomize, 0 for not). Example: `./main -w 2 -r 1` for random strong winds.

* I've written the code as legibly as possible. If you notice any inconsistencies or errors, please raise an issue. Thank you!
