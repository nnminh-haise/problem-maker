
# Problem making tool

> *This is a template for creating competitive problems*

---

## What is a competitive problem?

A competitive problem is a problem! It has a statement, an editorial, solutions. Moreover as a creater of the problem there will be a testcase generator and other related tool.

## What is this repository?

As described, this is a template folder containing basically the simpliest tool you need to get start to create competitive problem.

Most of the files are written in `cpp` except for the `creator.py`, more detail for each file below.

### The flow of making a competitive problem

- First you need to make the statement of the problem.
- Then you can begin to write the solution in any programming language you want. I suggest `c++` and `python`.
- Then, you can work on the problem's editorial, which is an indept description for your solution.
- Lastly, you will create the problems' testcases.

    1. A testcase set (or testcases) is a set of files represent the inputs and the respective outputs. ITMCs' club website is using `x.in` for the tests' input and `x.out` for the tests' output and `x` is the test indicator. Other website or platform will have other file format. For example, if the testcase has $10$ testcases, so there will be $20$ files from `1.in` to `10.in` and `1.out` to `10.out`, $20$ files in total.
    2. The problem will need a input generator, which is the `generator.cpp` file. This file will generate the correct input base on the problems' statement. So this file is a must when making a competitive problem.
    3. Some competitive problems will many answers. Therefore you will need a checker which check the submision output is correct or not. This feature is not included in this template. I'll come up with a solution for that type of problem in the ner future.
    4. Let says you need to create a testcase with $10$ testcases. You will repeat this process $10$ times: 
        - Create the problem input.
        - Run solution to create the respective output.

### What is `creator.py` ?

After understanding the flow of making competitive problem, the `creator.py` file is the file which will automated the above process for you.

All you need is a absoulute corrent solution of the problem and the absolute input generator of the problem. All named as `solution.cpp` and `generator.cpp`. Then you just need to run the file `creator.py` to generate the testcase for you.

## Downside of this template

As the creator of this repo, I see there are a lot of downside of this template.

- Firstly, the number of testcases will be generated is fixed. I hard code the number $40$ for every testcases. This value should be mutable by the users.
- Secondly, the strictly naming convension and type of the solution and input generator will related to `cpp` users only.
- Lastly, the lack of checker is a huge draw back while making the problem.

---

## Conclusion

Well there are rooms for improvement of this probject. I'll keep update this template in the future or turnning it into a CLI or an application for future usage.

See ya in the next update!
