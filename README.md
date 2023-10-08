<p align="center">
	<img src="https://github.com/maxencebonamy/maxencebonamy/blob/main/assets/Brainfuck_Interpreter.png" width="100%" alt="Brainfuck Interpreter">
</p>

<br>

<p align="center">
	<img src="https://github.com/maxencebonamy/maxencebonamy/blob/main/assets/1_Description.png" width="100%" alt="Description">
</p>

Brainfuck is a programming language containing just 8 instructions, each a character. This software is an interpreter that lets you execute a program written in Brainfuck.

We have an array of cells, each able to store 8 bits, i.e. an unsigned number between and including 255. Next, a pointer will point to a cell in the array (the first by default). This array will in fact represent memory throughout program execution.

The 8 instructions used are as follows:
- **`>`:** move pointer left
- **`<`:** shift pointer to the right
- **`-`:** decrement pointer value
- **`+`:** increment pointer value
- **`.`:** display pointer value as character
- **`,`:** user input of pointer value
- **`[`:** start of an scope
- **`]`:** end of an scope: return to the beginning if the pointed value is non-zero

<br>

<p align="center">
	<img src="https://github.com/maxencebonamy/maxencebonamy/blob/main/assets/2_Get_Started.png" width="100%" alt="Get Started">
</p>

### Launch the software:

1. Click on the <a href="https://github.com/maxencebonamy/Brainfuck-Interpreter/releases" target="_blank">Releases</a> button on the right and select the **latest version**.
2. Download the **.zip** archive and extract the files.
3. Open a terminal from the folder **Brainfuck-Interpreter** and run the folowwing command:
```
./Brainfuck-Interpreter.exe examples/hello_world.bf
```

### Compile:

> [!NOTE]
> *Prerequisites:*
> - [x] *Git must be installed on your computer. If not, <a href="https://git-scm.com/downloads" target="_blank">click here.</a>*
> - [x] *Xmake must be installed on your computer, if not, <a href="https://xmake.io/#/getting_started?id=installation" target="_blank">click here.</a>*
<br>

1. **Clone** the repository on your computer. To do this, open a terminal in the folder of your choice and run the following command:
```
git clone https://github.com/maxencebonamy/Brainfuck-Interpreter
```

2. **Navigate** inside the folder you've just cloned with the following command:
```
cd Brainfuck-Interpreter
```

3. **Compile** the project with the following command:
```
xmake
```

4. **Run** the executable with this command:
```
xmake run main examples/hello_world.bf
```

<br>

<p align="center">
	<img src="https://github.com/maxencebonamy/maxencebonamy/blob/main/assets/3_Features.png" width="100%" alt="Features">
</p>

### A few rules to follow when writing your program:
- The format of a Brainfuck file is `.bf` (you can actually use any format you like).
- You can write comments anywhere in the file, but be careful not to include any characters corresponding to instructions.
- The program will start to be interpreted from the first `#` character. This means that you have a text zone before this character, where you can write whatever you like, even with characters corresponding to instructions.
- There's already an example program `hello_world.bf` in the `examples` folder, which you can of course use as a basis for your own.
