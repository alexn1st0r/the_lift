# The Lift
# Synopsis

A multi-floor building has a Lift in it.
People are queued on different floors waiting for the Lift.
Some people want to go up. Some people want to go down.
The floor they want to go to is represented by a number (i.e. when they enter the Lift this is the button they will press)
```
BEFORE (people waiting in queues)               AFTER (people at their destinations)
                   +--+                                          +--+ 
  /----------------|  |----------------\        /----------------|  |----------------\
10|                |  | 1,4,3,2        |      10|             10 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 9|                |  | 1,10,2         |       9|                |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 8|                |  |                |       8|                |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 7|                |  | 3,6,4,5,6      |       7|                |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 6|                |  |                |       6|          6,6,6 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 5|                |  |                |       5|            5,5 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 4|                |  | 0,0,0          |       4|          4,4,4 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 3|                |  |                |       3|            3,3 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 2|                |  | 4              |       2|          2,2,2 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 1|                |  | 6,5,2          |       1|            1,1 |  |                |
  |----------------|  |----------------|        |----------------|  |----------------|
 G|                |  |                |       G|          0,0,0 |  |                |
  |====================================|        |====================================|
```
## Rules
### Lift Rules

1. The Lift only goes up or down!
2. Each floor has both UP and DOWN Lift-call buttons (except top and ground floors which have only DOWN and UP respectively)
3. The Lift never changes direction until there are no more people wanting to get on/off in the direction it is already travelling
4. When empty the Lift tries to be smart. For example,
4.1     If it was going up then it may continue up to collect the highest floor person wanting to go down
4.2     If it was going down then it may continue down to collect the lowest floor person wanting to go up
5. The Lift has a maximum capacity of people
6. When called, the Lift will stop at a floor even if it is full, although unless somebody gets off nobody else can get on!
7. If the lift is empty, and no people are waiting, then it will return to the ground floor

### People Rules

1. People are in "queues" that represent their order of arrival to wait for the Lift
2. All people can press the UP/DOWN Lift-call buttons
3. Only people going the same direction as the Lift may enter it
4. Entry is according to the "queue" order, but those unable to enter do not block those behind them that can
5. If a person is unable to enter a full Lift, they will press the UP/DOWN Lift-call button again after it has departed without them

### Task

1. Get all the people to the floors they want to go to while obeying the Lift rules and the People rules
2. Return a list of all floors that the Lift stopped at (in the order visited!)

NOTE: The Lift always starts on the ground floor (and people waiting on the ground floor may enter immediately)
## I/O
### Input

1. queues a list of queues of people for all floors of the building.
1.1 The height of the building varies
1.2 0 = the ground floor
1.3 Not all floors have queues
1.4 Queue index [0] is the "head" of the queue
1.5 Numbers indicate which floor the person wants go to
2. capacity maximum number of people allowed in the lift

Parameter validation - All input parameters can be assumed OK. No need to check for things like:

1. People wanting to go to floors that do not exist
2. People wanting to take the Lift to the floor they are already on
3. Buildings with < 2 floors

## Check it!

1. `` make clean all``
2. ``./main``
