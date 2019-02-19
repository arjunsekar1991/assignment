Testing sequence creation and printing
--------------------------------------
Sequence:  100,200,300,0
Should be: <100, 200, 300, ???>

Testing multiple sequences
--------------------------
Sequence1: 0,1,2
Sequence2: 100,101,102
Should be: <0, 1, 2>
           <100, 101, 102>

Testing push_back()
-------------------
Sequence:  100,200,300,400,500
Should be: <100, 200, 300, 400, 500>

Testing push_back() on an empty sequence
-------------------
Sequence:  100,200,300,400,500
Should be: <100, 200, 300, 400, 500>

Testing pop_back()
------------------
Sequence:   100,200,300
Should be:  <100, 200, 300>

Testing pop_back() on an empty sequence
------------------
CORRECT: Threw exception: sequence is empty pop_back failed :)

Testing insert()
------------------
Sequence:   100,200,300,999,400,500
Should be:  <100, 200, 300, 999, 400, 500>

Sequence:   888,100,200,300,999,400,500
Should be:  <888, 100, 200, 300, 999, 400, 500>

Sequence:   888,100,200,300,999,400,500,777
Should be:  <888, 100, 200, 300, 999, 400, 500, 777>

Testing insert() on an invalid index
------------------
CORRECT: Threw exception: Invalid Index

Testing front()
---------------
Front:     100
Sequence:  100,200,300
Should be: 100
           <100, 200, 300>

Testing front() on an empty sequence
------------------------------------
CORRECT: Threw exception: Invalid index :)

Testing back()
---------------
Back:      300
Sequence:  100,200,300
Should be: 300
           <100, 200, 300>

Testing back() on an empty sequence
------------------------------------
CORRECT: Threw exception: Invalid index :)

Testing empty()
---------------
Empty sequence, empty returns: 1
Non-empty sequence, empty returns: 0

Testing size()
---------------
Sequence length 7, size returned: 7
Empty sequence, size returned: 0

Testing clear()
---------------
Sequence cleared, empty returned: 1
Size returned:  0

Testing erase()
------------------
Sequence:   100,200,300,800,900,1000
Should be:  <100, 200, 300, 800, 900, 1000>

Sequence:   100,200,300,800
Should be:  <100, 200, 300, 800>

Sequence:   300,800
Should be:  <300, 800>

Testing erase() on invalid parameters
------------------
CORRECT: Threw exception: Invalid index

Testing assignment (=) operator
------------------
Data1:      100,200,300,400,500
Data2:      1,2,300,400,500
Should be:  <100, 200, 300, 400, 500>
            <1, 2, 300, 400, 500>

Testing copy constructor
------------------
Copied Sequence:        1,200,300,400,500
Original Sequence:      100,200,300,400,500
Should be:              <1, 200, 300, 400, 500>
                        <100, 200, 300, 400, 500>


C:\Users\arjun\Documents\Github\assignment\assignment\x64\Debug\project1.exe (process 10600) exited with code 0.
Press any key to close this window . . .