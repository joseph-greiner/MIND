# MIND: Modular-IN2-Nixie-Display
This is a modular display made for Russian IN2 Nixie tubes. Each display contains 2 tubes and 2 LED decimal places. These can be stacked up as many as you would like, as long as the high voltage supply can provide the necessary current to run them.<br>

Version 1:<br>
  Basic disply functionality achieved. Yay!<br>
  An example of the current progress is at https://youtu.be/8mW3LZJ6aFY <br>
  <b>TODO:</b>
  <ul>
    <li>Add a current limiting circuit to the module, ideally no more than 2mA should be supplied to each tube.</li>
    <li>Change the connection header so that the boards can be stacked easier. Perhaps add a header to each side of the board.</li>
    <li>Change the shift register so that each module can shift the data out to the next, not sure what I was thinking.</li>
    <li>Decide on a better plan for the decimal places, the current one is cludgy and I don't like it.</li>
  </ul>



Each module is built up from one shift register and two BCD to decimal IC's and discrete components. The cost of each individual module was a high priority for me, so I have done my best to keep them under $5 US. Which achievable depending upon where your PCB's are made.
