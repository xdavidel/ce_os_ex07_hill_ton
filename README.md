# Hill Ton

## Introduction
Have you ever carried a ton of weight up a hill? Well, we hope you don’t, and even if you did - you
should probably do it in smaller steps, carefully, knowing what you’re doing..

## Up the hill
This time, we do not want to map the file as a whole, but we would like to carry the minimal
amount of data for best efficiency, both in allocations and reads.
The program you are writing should change the order of the file contents by a first seen first printed
manner, while each byte is printed the total amount of times it is shown in the entire file. For
example: A file with the contents ZABBBBEAAAAZZDDKEKEKA will be printed as follows
ZZZAAAAAABBBBEEEDDKKK
The focus here shouldn’t be on the sorting efficiency - but about proper memory management,
memory should be reserved when necessary, actual allocations should be performed only when
necessary, proper protection and sizes are very relevant. Minimal memory footprint is the goal.
The memory shouldn’t be writable by anyone else during the sorting process!

## Remarks
* Only usage of WinAPI is allowed. You can use C-library for input/output only. - Code should be organized, and API should be picked wisely, and used carefully as needed.
* You can investigate the memory and program state using SysInternals, Task Manager, or printing
out statuses during the execution.
* Please do not use heap APIs - you should manage your own virtual memory!

## Your Submission
Please submit the necessary code files, along with an explanation of your choices, examination
process and the memory footprint you are expecting.
Step by step, you can make it to the top!

## References
* Your previous lesson.
* MSDN