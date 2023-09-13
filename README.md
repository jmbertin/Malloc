# Malloc
Malloc is a project undertaken as part of the 42 school curriculum. In this project, we have implemented our own versions of the `malloc`, `free`, and `realloc` functions to dynamically manage memory in C programs. The implementation is based on a paging system and includes three types of memory zones: tiny, small, and large, which help in optimizing memory allocation.

**Developed and tested on a Linux Ubuntu 23.04.**

----

## Build and Installation

Clone the repository:

``git clone https://github.com/jmbertin/Malloc/``

Navigate to the project directory and compile using Makefile:

``cd Malloc``

``make``

----

## Memory Zone Definitions

Our memory manager operates with three types of zones to optimize allocations:

1. **Tiny Zone**:
    - Type: 1
    - Max block size: 128 bytes
    - Zone size: 16384 bytes (4 pages of 4096 bytes each)

2. **Small Zone**:
    - Type: 2
    - Max block size: 1024 bytes
    - Zone size: 106496 bytes (26 pages of 4096 bytes each)

3. **Large Zone**:
    - Type: 3
    - Block size: Varies
    - Zone size: Varies (size + sizeof(t_zone) + sizeof(t_block))

----

## Data Structures

### t_zone

The `t_zone` structure represents a memory zone and includes the following fields:
- `prev`: A pointer to the previous zone
- `next`: A pointer to the next zone
- `type`: The type of zone (1, 2, or 3 corresponding to tiny, small, or large)
- `total_size`: The total size of the zone
- `free_size`: The available free size within the zone
- `block_count`: The number of blocks in the zone

### t_block

The `t_block` structure represents a memory block and includes the following fields:
- `size`: The size of the block
- `free`: An indicator to know whether the block is free or not
- `next`: A pointer to the next block
- `prev`: A pointer to the previous block

----

## Thread Safety

The implementation employs a `g_malloc_mutex` mutex to ensure thread safety during memory allocation and release.

----

## Usage

- Compile the library
- Copy the .so file and includes folder into your .c folder
- Export environnement variable to override the standard malloc functions with :
````
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
````
- Compile your project with
````
gcc [your .c files] -L. -lmalloc_x86_64_Linux -o [binary output name]
````

----

## Test
To make some tests, just do :

````
cd tests
chmod +x tests.sh
./tests
````

----

## Contribution
If you encounter any bugs or wish to add features, please feel free to open an issue or submit a pull request.
