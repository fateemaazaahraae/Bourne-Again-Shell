<h1><strong>✏️ minishell : </strong></h1>
<p><i>Create a basic computer graphics project! </i><p><br>
<p><i>This project is about creating a simple shell. Yes, your own little bash. <br> You will learn a lot about processes and file descriptors.</i></p><br>
<h1>💡 About the project : </h1>
<h3>Your shell should:</h3>
<ul>
  <li>Display a <strong>prompt</strong> when waiting for a new command.</li>
  <li>Have a working <strong>history</strong>.</li>
  <li>Search and launch the right executable (based on the <strong>PATH</strong> variable or using a relative or an absolute path).</li>
  <li>Not use more than <strong>one global variable</strong>. Think about it. You will have to explain its purpose.</li>
  <li>Not interpret unclosed quotes or special characters which are not required by the
subject such as \ (backslash) or ; (semicolon).</li>
  <li>Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.</li>
  <li>Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).</li>
  <li>Implement <stong>redirections</stong>:
    <ul>
      <li>< should redirect input.</li>
      <li>> should redirect output.</li>
      <li><< should be given a delimiter, then read the input until a line containing the
delimiter is seen. However, it doesn’t have to update the history!</li>
      <li>>> should redirect output in append mode.</li>
    </ul>
  </li>
  <li>Implement <strong>pipes</strong> (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.</li>
  <li>Handle <strong>environment variables</strong>($ followed by a sequence of characters) which
should expand to their values.</li>
  <li>Handle $? which should expand to the exit status of the most recently executed
foreground pipeline.</li>
  <li>Handle <strong>ctrl-C, ctrl-D and ctrl-\</strong> which should behave like in bash.</li>
  <li>In interactive mode:
    <ul>
      <li><strong>ctrl-C</strong> displays a new prompt on a new line.</li>
      <li><strong>ctrl-D</strong> exits the shell.</li>
      <li><strong>ctrl-\</strong> does nothing</li>
    </ul>
  </li>
  <li>Your shell must implement the following <strong>builtins:</strong>
    <ul>
      <li>echo with option -n</li>
      <li>cd with only a relative or absolute path</li>
      <li>pwd with no options</li>
      <li>export with no options</li>
      <li>unset with no options</li>
      <li>env with no options or arguments</li>
      <li>exit with no options</li>
    </ul>
  </li>
</ul>
<h4>⚠️ You should limit yourself to the subject description. Anything that is not asked is not required. If you have any doubt about a requirement, take <link rel="bash" href="https://www.gnu.org/savannah-checkouts/gnu/bash/manual/"> as a reference.</h4>

<h3>Bonus Part :</h3>
<ul>Your program has to implement:
  <li> && and || with parenthesis for priorities.</li>
  <li>Wildcards * should work for the current working directory.</li>
</ul>
<br><br>

<h1>💯 Final Grade : </h1> <br>
