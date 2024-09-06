# R-25 Test

How my code works():
1.in the parsing.c folder
  ---i have defined the input min max and output min max;
  ---Define the neutral point
  ---Mapped the channel value to a PWM value between OUTPUT_MIN and OUTPUT_MAX
  ---If channel value is less than neutral, calculate the PWM for backward direction
  ---If channel value is greater than neutral, calculate the PWM for forward direction
  ---If channel value is neutral, set PWM to neutral value
  ---Ensure PWM value is within the valid range
 
2.---in main function in ( this functiion present in  serial "void read_SBUS(uint8_t* buffer, size_t size, size_t n, FILE* file_ptr)")
  the sytax is wrong and has been change to "read_SBUS(sbus_packet, sizeof(uint8_t), 25, sbus)" ;previously size of was not mentioned;

3.output {--------------------------------------------
Checking...
Test-1: 
./main.exe test/sbus_data\[1\] test/sab_data[1]
diff test/sab_data[1] test/expected[1]
--- test/sab_data[1]
+++ test/expected[1]
@@ -1 +1 @@
-21
\ No newline at end of file
+11
\ No newline at end of file
make: *** [makefile:13: check] Error 1}

ways to fix 
----> adjust function for desired output 
---->Make sure there are no off-by-one errors in the calculation, especially if the input values or ranges are off by 1 or have been misinterpreted.
---->Debug with Known Values
---->Check for Negative Values
---->Ensure Proper Formatting in Output
























.<p align="center">
  <img src="https://github.com/teamrudra/r25-test/blob/main/datasheets/rover.jpeg" width="600" height="300"/>

#### Some Instructions
1. You may use any online resources, datasheets, or documentation needed, but be mindful of your time and stay focused on the task.
2. The duration of the test is 90 mins from 5:15pm to 6:45 pm.
3. There will be a MCQ test conducted [here](https://r25.munmap.net)
4. There are 3 tasks in the tests. Complete all of them.
5. In case you are not able to complete all the tasks, do upload the whatever you are able to do.
6. In the `README.md` of your repository include your thought process, places where you got stuck, where you used the help of chatGPT, google or other online resources.
7. Even if you are not able to solve anything. Do fill the readme and what your thought process would have been.
8. Carefully read the instructions to implement the required functionality.
9. Install [mingw(c compiler)](https://www.mingw-w64.org/downloads/#w64devkit) and [git](https://git-scm.com/downloads) if you haven't already done it.
10. After finishing your test, provide the link to your forked repository in the google form provided at the end.
     
### Aim/Objective: You are implementing code to control motors for a rover using data received from an RC transmitter.
## Description
You are implementing code to control a sabrtooth motor driver(we are only trying to control motor 1 using S1 of Sabertooth), connected to drive motors of the rover, using data received from an [RC transmitter](datasheets/transmitter-manual.pdf)(make note that the transmitter is configured to transmit data in extended limits). The data from the transmitter is being recieved by a SBUS reciever module, you can find about the data protocol used [here](https://github.com/bolderflight/sbus/blob/main/README.md). 

### Task 0: Fork the provided repository and ensure it is set to PUBLIC so we can access and assess your work.
### Task 1: Interpolation for Sabertooth.
The motor driver (`Sabertooth 2x60`) in the simplified serial mode (check out the [datasheets](datasheets/sabertooth(2x60).pdf))
Your task is to interpolate a channel value into the format accepted by the motor driver, and make the rover move in forward or backward direction.
### Task 2: Compile and run the code.

#### Code
1. [src/main.c](src/main.c): Code for running the test.
2. [lib/parsing.c](lib/parsing.c): Complete the defined `interpolation` function here.

#### How to Compile & Check your code
(make sure you are in the root directory)   
1. Compile your code by running: `make build`
2. To check if your code is implemented correctly run: `make check`
   
If you are able to compile your code successfully you should see something like this on your screen:

<p align="center">
  <img src="https://github.com/teamrudra/r25-test/blob/main/datasheets/make_check_succesfull.png" width="600" height="300"/>
</p>

4. If your make check was unsuccesfull, you can clean your attempt by running `make clean`, review your implementation and repeat the previous steps.

# Solution
## Understanding
Describe what you understood about the problem.

## Thought Process
After understanding the problem, describe how you decided to proceed towards solving the question.

## Implementation
How did you decide to implement your solution.

Mention the details, such as the scaling used in the interpolation and how you tested it.

# Google Form
[Link to Repo Submission](https://docs.google.com/forms/d/e/1FAIpQLSeKVbm2dqWxwA5lbEkRfzY8KF619mI5ibGs0Cm2e5wrb0hoWQ/viewform)


<p align="center">
  <img src="https://github.com/teamrudra/r25-test/blob/main/datasheets/feynman-simple.jpg" width="600" height="600"/>
</p>
