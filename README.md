# The **tube** Project

![-tube-](./img/tube.png)

**tube** is a command line project for building calculation models quickly. These models are consisted of a sequence of functions executing calculations/permutations onto a user-defined input. Each function takes as input the output of the previous function and outputs the result to the next one.

---

## Format

The format of the formulas/models is:
  `- <input-function> - <function> - ... - <function> -`
 where:
  1. `<input-function>` is a function that reads the `<input-file>` and imports it into the appropriate form.
  2. `<function>` is a function executing a calculation on an input and generating an output.

  Notice that every calculation is separated with dashes from the next one and previous one, as well as, the whole model starts with a dash and ends with a dash.
  In *Functions* section there is an analytical documentation for each function.

---

## Functions

- #### input-functions ####
  - `- num -`: specifies that the input is a number
  - `- array<num> -`: specifies that the input is an array with <num> positions

- #### functions ####
  - `- add<num> -`: adds `<num>` to the input. (input: num, output: num)
  - `- sub<num>` -: subtracts `<num>` from the input. (input: num, output: num)
  - `- mult<num> -`: multiplies the input with the `<num>`. (input: num, output: num)
  - `- pow<num> -`: input to the power of `<num>`. (input: num, output: num)
  - `- med -`: outputs the median value of an input array. (input: array, output: num)
  - `- mean -`: outputs the mean value of an input array. (input: array, output: num)
  - `- max -`: outputs the maximum value of an input array. (input: array, output: num)
  - `- min -`: outputs the minimum value of an input array. (input: array, output: num)
  - `- bp -`: breakpoint. prints the value and and passes it to the next function. (input: anything, output: input)
  - `- extract -`: extracts the value to a predefined file and passes it to the next function. (input: anything, output: input)

---

## Examples

- model: `-num-add3-pow2-`,
  with input: `2`,
  gives output: `(2+3)^2=25`.

- model: `-array5-mean-mult8-`,
  with input: `2,5,8,1,4`,
  gives output: `((2+5+8+1+4)/5)*8=32`.

- model: `-array10-max-add5-`,
  with input: `1,2,3,4,5,6,7,8,9,10`,
  gives output: `10+5=15`.

---

## Compile

Use the gcc compiler to compile the project. Type the following to compile:

```bash
make
```

---

## Usage

```bash
./bin/tube <input-file-path> <model-file-path>
```
or
```bash
cd bin
./tube <input-file-path> <model-file-path>
```

to execute.

---

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

---

## License
[MIT](https://choosealicense.com/licenses/mit/)
