
# The tube project

**tube** is a command line project for building calculation models quickly. These models are consisted of a sequence of functions executing calculations/permutations onto a user-defined input. Each function takes as input the output of the previous function and outputs the result to the next one.

<img src="./img/tube.png" alt="blender tubes" style="display: block; margin-left:auto; margin-right:auto; margin-top:30px; margin-bottom:30px; width:99%; border-radius:10px;">  


## Format

The format of the formulas/models is:  
  `- <input-function> - <function> - ... - <function> -`  
 where:  
- `<input-function>` is a function reading and converting the `<input-file>` into the appropriate form.  
- `<function>` can be a function executing a calculation/permutation.

Notice that every calculation is separated with dashes from the next and previous one, as well as, the whole model starts with a dash and ends with a dash. You can find analytical documentation for each function in [Functions](#functions) section.  

## Examples

- model: `-num-add3-pow2-`,
  with input: `2`,
  gives output: `(2+3)^2=25`.

- model: `-array5-sort-idx1-`,
  with input: `2 5 8 1 4`,
  gives output: `2`.

- model: `-array10-max-add5-`,
  with input: `1 2 3 4 5 6 7 8 9 10`,
  gives output: `10+5=15`.

Here is an example of finding a week's average temperature in Celsius and converting it to Fahrenheit:

<img src="./img/screenshot.png" alt="model screenshot" style="display: block; margin-left:auto; margin-right:auto; margin-top:30px; margin-bottom:30px; width:99%; border-radius:10px;">


## Functions

### input-functions:
  - `num`: specifies that the input is a number
  - `array<num>`: specifies that the input is an array with <num> positions

### functions:
  - `add<num>`: adds `<num>` to the input. (input: num/array, output: num)
  - `sub<num>`: subtracts `<num>` from the input. (input: num/array, output: num)
  - `mult<num>`: multiplies the input with the `<num>`. (input: num/array, output: num)
  - `pow<num>`: input to the power of `<num>`. (input: num/array, output: num)
  - `med`: outputs the median value of an input array. (input: array, output: num)
  - `mean`: outputs the mean value of an input array. (input: array, output: num)
  - `max`: outputs the maximum value of an input array. (input: array, output: num)
  - `min`: outputs the minimum value of an input array. (input: array, output: num)
  - `bp`: breakpoint. prints the value and and passes it to the next function. (input: anything, output: inp)
  - `extract`: creates an `./output.txt` file and extracts the input. (input: anything, output: inp)
  - `sort`: sorts a given array. (input: array, output: num)
  - `idx<num>`: outputs the `<num>`th element of a given array. (input: array, output: num)


## Compile

Download and use the gcc compiler to compile the project. Depending on your operating system, type the following to compile:

#### Linux:
```bash
make
```
to compile, and:
```bash
make clean
```
to clean.

#### Windows:
```bash
gcc -o bin/main.o -c src/main.c
gcc -o bin/lex.o -c src/lex.c
gcc -o bin/tube.o -c src/tube.c
gcc -o bin/utils.o -c src/utils.c -lm
gcc -o ./tube bin/main.o bin/tube.o bin/lex.o bin/utils.o -lm
```
to compile, and:
```bash
del -f ./tube
del -f bin/main.o
del -f bin/lex.o
del -f bin/utils.o
```
to clean.

## Usage

Type: `tube <command> [<args>]` to execute.

Here is a list of all the available commands: <br/>

**path modification**:
  - `model`: Define model file path
  - `input`: Define input file path
  - `output`: Define output file path
  - `clear`: Delete all the paths
  <br/>
    
**model execution**:
  - `compile`: Compile and print the model
  - `demo`: Run a demonstration model
  - `run`: Run the model using user-defined paths

You can use input and model samples from the `./input`, `./model` sub-directories,
or you can create and use your own models.

> NOTE: Use `tube` instead of `./tube` on Windows.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0)
