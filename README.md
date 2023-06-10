---


---

<h1 id="gpa-calculator">GPA Calculator</h1>
<p>This repository contains a GPA Calculator program written in C++. The program allows users to input and manage student data, including their subjects, scores, credit hours, and grade points. It calculates the CGPA (Cumulative Grade Point Average) for each student and provides various functionalities to interact with the data.</p>
<h1 id="table-of-contents">Table of Contents</h1>
<ul>
<li><a href="#getting-started">Getting Started</a></li>
<li><a href="#compilation">Compilation</a></li>
<li><a href="#usage">Usage</a></li>
<li><a href="#features">Features</a></li>
<li><a href="#contributing">Contributing</a></li>
<li><a href="#valgrind-report">Valgrind Report</a></li>
<li><a href="#author">Author</a></li>
</ul>
<h2 id="a-idgetting-startedagetting-started"><a id="getting-started"></a>Getting Started</h2>
<p>To get started with the GPA Calculator, follow these steps:</p>
<p>Clone the repository to your local machine.</p>
<blockquote>
<pre><code>bash 
git clone https://github.com/ZorEl212/CGPA-Calculator.git
</code></pre>
</blockquote>
<p>Change into the project directory.</p>
<blockquote>
<pre><code>cd CGPA-Calculator
</code></pre>
</blockquote>
<h2 id="a-idcompilationacompilation"><a id="compilation"></a>Compilation</h2>
<p>To compile the GPA Calculator, make sure you have a C++ compiler installed on your system. Here’s how you can compile the source code:</p>
<p>Open a terminal or command prompt.<br>
Navigate to the project directory.<br>
Run the following command to compile the source code.</p>
<blockquote>
<pre><code>bash 
g++ *.cpp -o gpa-calculator
</code></pre>
</blockquote>
<p>Once the compilation is successful, an executable file named</p>
<blockquote>
<p>gpa-calculator</p>
</blockquote>
<p>will be generated.</p>
<h2 id="a-idusagea-usage"><a id="usage"></a> Usage</h2>
<p>The program provides a command-line interface to interact with the functionalities. Here’s how you can use it:</p>
<p>Run the compiled executable.</p>
<blockquote>
<pre><code>./gpa-calculator
</code></pre>
</blockquote>
<p>Choose an option from the menu to perform specific actions, such as adding a student, inputting subject details, calculating CGPA, etc.<br>
Follow the on-screen prompts to provide the required information.<br>
View the calculated CGPA and other details.</p>
<p>To import inputs from a file follow these steps.</p>
<ol>
<li>Create a text file</li>
<li>Open the file and enter your records in this format</li>
</ol>
<blockquote>
<pre><code>Name
[subject],[score],[credithours]
[subject2],[score],[creditHours]
</code></pre>
</blockquote>
<p>For example:</p>
<blockquote>
<pre><code>Yeab
Eng,85,5
Physics,77,5
Math,77,5
</code></pre>
</blockquote>
<ol start="3">
<li>Save and exit.</li>
<li>Then choose “load from file” option in the program and calculate your results.</li>
</ol>
<h2 id="a-idfeaturesa-features"><a id="features"></a> Features</h2>
<p>The GPA Calculator offers the following features:</p>
<ul>
<li>Adding and managing student records.</li>
<li>Adding and managing subject details for each student.</li>
<li>Calculating CGPA based on the entered data.</li>
<li>Saving and loading data to/from a file.</li>
<li>Displaying student information and CGPA.</li>
</ul>
<h2 id="a-idvalgrind-reporta--valgrind-report"><a id="valgrind-report"></a>  Valgrind Report</h2>
<pre><code>==23514== 
==23514== HEAP SUMMARY:
==23514==     in use at exit: 0 bytes in 0 blocks
==23514==   total heap usage: 17 allocs, 17 frees, 84,319 bytes allocated
==23514== 
==23514== All heap blocks were freed -- no leaks are possible
==23514== 
==23514== For lists of detected and suppressed errors, rerun with: -s
==23514== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
</code></pre>
<h2 id="a-idcontributinga-contributing"><a id="contributing"></a> Contributing</h2>
<p>Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request. Please follow the contribution guidelines outlined in the repository.<br>
License</p>
<h2 id="author">Author</h2>
<p>Yeabsira Desalegn<br>
<a href="mailto:yabsirad212@gmail.com">yabsirad212@gmail.com</a></p>

