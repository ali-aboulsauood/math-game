# Math Game

This is a simple practice project for a game of elementary math questions - written in C++.
<i>This project was created as part of a [course](https://programmingadvices.com/p/00316b1111) offered by [ProgrammingAdvices](https::\\programmingadvices.com).</i>

## Installation and Launch

Download [`MathGame.exe`](https://github.com/ali-aboulsauood/math-game/blob/main/MathGame.exe) and run the executable (the <i>game</i>).

## Rules and Instructions

<i>Basic instructions are provided in the game itself. The following describes the game rules and instructions in more detail.</i>

1. Enter the number of questions you wish to answer in the <i>quiz</i>, then press <code>Enter</code> to confirm.
2. Enter the number corresponding to the difficulty level of the questions from the <i>Select Difficulty Level</i> menu that appears, then press <code>Enter</code> to confirm.\
   <br>
   The game has three difficulty levels, in addition to a <i>Mix</i> option:
   <ol type = "1">
     <li>
       <b><dfn>Easy</dfn></b>: The operands used in the questions are between <code>1</code> and <code>10</code> (inclusive).
     </li>
     
     <li>
       <b><dfn>Medium</dfn></b>: The operands used in the questions are between <code>11</code> and <code>50</code> (inclusive).
     </li>
     
     <li>
       <b><dfn>Hard</dfn></b>: The operands used in the questions are between <code>51</code> and <code>100</code> (inclusive).
     </li>

     <li>
       <b><dfn>Mix</dfn></b>: The difficulty level of each question is randomly set to one of the three aforementioned difficulty levels.
     </li>
   </ol>
3. Enter the number corresponding to the arithmetic operation of the questions from the <i>Select Arithmetic Operation</i> menu that appears, then press <code>Enter</code> to confirm.\
   <br>
   The game has three arithmetic operations, in addition to an <i>All</i> option:
   <ol type = "1">
     <li>
       <b>Addition</b>
     </li>
     <li>
       <b>Subtraction</b>
     </li>
     <li>
       <b>Multiplication</b>
     </li>
     <li>
       <b>Division</b>: Round the result to the nearest integer, with halfway cases rounded away from zero (if <code>a</code> is the integer portion and <code>x</code> is the non-integer portion, round <code>a.x</code> to <code>a</code> if <code>x &lt; 5</code> and to <code>a + 1</code> if <code>x &gt;= 5</code>)
     </li>
     <li>
       <b>All</b>: The operation of each question is randomly set to one of the four aforementioned arithmetic operations.
     </li>
   </ol>
4. For each question, enter your answer and press <code>Enter</code> to confirm and proceed to the next question.\
   <br>
   If your answer is correct, the console background color becomes green; if not, it becomes red, and the correct answer is displayed.

<br>

After answering the number of questions you have specified, the console background color becomes green if you passed the quiz (the number of correct answers is greater than or equal to that of the incorrect answers), and red otherwise.\
A Game Over screen shows the number of questions, difficulty level, arithmetic operation, and the number of correct and incorrect answers. there is an option to start a new quiz.

## Future Updates
Allah willing, the game is going to have both console and GUI editions, and the following features:

1. A time limit for each question, depending on the difficulty and arithmetic operation of each question.
2. An option to export quiz results to a text file or an HTML file.
3. An option to start a new quiz with the same difficulty and arithmetic operation chosen for the last quiz.
3. An option to keep a record of all quizzes taken by the user, which can be used to generate a report of the player's performance over multiple quizzes.

## Suggestions and Contributions
If you have any suggestions regarding the program, feel free to [email me](aliaboulsauood@gmail.com) or message me [LinkedIn](https://github.com/ali-aboulsauood/ali-aboulsauood/blob/main/www.linkedin.com/in/ali-aboul-sauood).

If you are a programmer or still learning to program, feel free to contribute to my project: [Math Game Github Repository](https://github.com/ali-aboulsauood/math-game).
