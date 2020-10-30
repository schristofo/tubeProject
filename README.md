
# The tube project

**tube** is a command line project for building calculation models quickly. These models are consisted of a sequence of functions executing calculations/permutations onto a user-defined input. Each function takes as input the output of the previous function and outputs the result to the next one.

<img src="./img/tubes.png" alt="blender tubes" style="display: block; margin-left:auto; margin-right:auto; margin-top:30px; margin-bottom:30px; width:99%; border-radius:10px;">


## Format

The format of the formulas/models is:  
  `- <input-function> - <function> - ... - <function> -`  
 where:  
- `<input-function>` is a function reading and converting the `<input-file>` into the appropriate form.  
- `<function>` can be a function executing a calculation/permutation.

Notice that every calculation is separated with dashes from the next and previous one, as well as, the whole model starts with a dash and ends with a dash. You can find analytical documentation for each function in [Functions](#functions) section.


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
  - `extract`: extracts the input to an output file and passes it to the next function. (input: anything, output: inp)
  - `sort`: sorts a given array. (input: array, output: num)
  - `idx<num>`: outputs the `<num>`th element of a given array. (input: array, output: num)


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

## Compile

Use the gcc compiler to compile the project. Depending on your operating system, type the following to compile:

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
gcc -c -o ./obj/main.o -c ./src/main.c
gcc -c -o ./obj/lex.o -c ./src/lex.c
gcc -c -o ./obj/utils.o -c ./src/utils.c -lm
gcc -o ./bin/tube ./obj/main.o ./obj/utils.o ./obj/lex.o
```
to compile, and:
```bash
rm ./bin/tube
rm obj/main.o
rm obj/lex.o
rm obj/utils.o
```
to clean.

## Usage

#### Linux:
```bash
./bin/tube <input-file-path> <model-file-path>
```
or
```bash
cd bin
./tube <input-file-path> <model-file-path>
```


to execute. You can use input and model samples from the `./input`, `./model` sub-directories,
or you can create and use your own models.

> NOTE: Use `tube` instead of `./tube` on Windows.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.


## License
[Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0)
