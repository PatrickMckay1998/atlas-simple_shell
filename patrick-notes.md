So far I have a program that asks for user input, takes that input and prints it out. 

Now we need to add an infinite loop - DONE

The program also needs to take in more than one arguement, it only takes one word and no more - WRITTEN/NEEDS DEBUG
- My program takes multiple inputs but it goes through the loop every time, prints out 'enter command' and then displays the input until all the words are displayed
- I am not sure how to get it to display the full string on just one line, I was thinking of adding a counter inside of the second while loop


I really think taking the execve command and putting it into its own prototype file will help 

execve(pathname, argv, envp)
-pathname: the pathname of the command to execute
-argv: the arguments to pass to the new program
-envp: the envirnment list

Does execve terminate the entire program of will it only take over the program in the loop
We need to create pid_t child_proc; after that variable is created
we go to the next line and add child_proc = fork(); and that creates the child process

After the child process is created we will check that we are in the child process of the fork using if (child_proc == 0) 
the reason we check for zero is because the PID should be 0, if it zero then we are in the child process and there is where 
we run the execve command. BOOM. 

Then we need to use the wait(NULL) outside of the loop which causes the parent to wait for the child process to finish and then it continues on with the parent process which in our case is the infinite loop, so it will execute the command in the child process we get those results then it goes back to asking for another input. 
BING BANG BOP 


HIGH LEVEL OVERVIEW OF CODE

Create the string using  input from printf and scanf

After input is recieved, create variable called delimiter and set it to equal a space then create variable called token and use strtok to tokenize the string that was input previously

Once the string is turned into a token, use fork to create a child process

Check to see if the child process was created successfully

if child process was created successfully then we use the execve command to run whatever command was put in

We error out if the user enters an unknown command

if the execve is successful then we use the wait command and wait for the child process to terminate

then theorhetically the program should wait for another input.

if we need to use getenv to get the PATH for execve to use because getenv compares whatever you set your *name variable to. because in our example for execve we are using usr/bin/ls which is the path for ls so in theory name would be set to ls and then getenv would get that path?

