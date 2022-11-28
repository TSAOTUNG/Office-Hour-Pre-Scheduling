# Office-Hour-Pre-Scheduling
Description
Since the midterm exam for Data Structures is around the corner, many students in the class start making appointments with the TAs to ask questions. However, there are only a limited number of TAs in the class. One TA can only deal with one appointment at a time. Therefore, we need a scheduling system to arrange appointments during the office hour.

In the system, there is a timeline with time units starting from 0. The timeline records a span of office hour, which contains the TAs’ working time. Students can try to schedule their appointments within TAs’ working time. The rules for appointment scheduling are as follows.

For the TAs’ working time, the TAs can add their start times and end times to the system. The start times for each TA can be different. But all the TAs share the same end time on the system. If all the TAs have no appointments to deal with, it’s fine to bring forward the end time for office hour. For example, TA Ricky starts working at the 5th time unit, while TA Rain starts working at the 10th time unit. They schedule the end time at the 30th time unit originally. However, if no appointments are being processed / will be processed in the system, the end time can be rescheduled to the 20th time unit. 

One thing to note: The office hours will last forever if the end time is not added to the system and TAs keep working. However, if the end time is added to the system, all TAs stop working at the specified time.

As for the students’ appointments, each appointment is taken as a task in the system. A task will be distributed to a TA who is both in working time and has the longest available time. A task should be scheduled once the TA becomes available. Students also need to provide the time consumption of their appointments in time units. If a task can be done before the end time of office hour, that task will be accepted and arranged. On the contrary, if a task is too long to fit into the rest of the office hour for the TA, the task will not be accepted. For example, a 30-time-unit task is distributed to TA Ricky at the 5th time unit. The end time of office hour is at the 30th time unit. Therefore, this task will not be accepted because (5+30)>30.

If multiple TAs are equally available, assign the task to the TA with the smallest name in lexicographic order. For example, TA Ricky and TA Rain are both available since the 0th time unit. When a task is to be assigned, it should be handed over to TA Rain because the string "Rain" is smaller than the string "Ricky" in lexicographic order.

One thing to note: Tasks that have already been scheduled cannot be rescheduled in any situation.

According to the above demands, you need to design a system that meets the needs of both students and TAs. This system contains four instructions.

1. ADD_TA
Add a TA to the system with his name and the time to start working, aka start time. A TA can only be added to the system if his start time is earlier than the end time of office hour.
Usage: ADD_TA $TA_NAME $START_TIME
Parameter: 
$TA_NAME: TA's name
$START_TIME: A non-negative integer represents the time that a TA starts serving. TA cannot be added if the time to start the service has exceeded the end time of office hour.
Example: 
ADD_TA Ricky 0: Add a new TA named Ricky, who starts serving from the 0th time unit.

2. ADD_TASK
Try to add a task, with its time consumption, to the system. Assign the task to the TA who is in working time and has the longest available time. If the task will be completed after the end time of office hour, the task will not be accepted.
Usage: ADD_TASK $TASK_NAME $COST_TIME
Parameter:
$TASK_NAME: A string represents the name of the task.
$COST_TIME: A non-negative integer represents the time span this task will take.
Example:
ADD_TASK Task1 50: Add a task named Task1 that takes 50 time units.

3. SET_ENDTIME:
Set a new end time for office hour. The newly assigned end time cannot be earlier than any scheduled tasks. Note that there is no end time in default status. (It means all of the tasks can be accepted.)
Usage: SET_ENDTIME $END_TIME
Parameter: 
$END_TIME: A non-negative integer represents the end time of office hour.
Example: 
SET_ENDTIME 480: The office hour will end at the 480th time unit.

4. CHECK_SCHEDULE
Check if a task can be scheduled. Given the task’s time consumption and the expected finish time of the task. If the TA can complete the task within both the expected finish time of the task and the end time of the office hour, the task can be scheduled.
Usage: CHECK_SCHEDULE $COST_TIME $FINISH_TIME
Parameter: 
$COST_TIME: A non-negative integer represents the time span this task requires.
$FINISH_TIME: is a non-negative integer that represents the expected time to complete this task.
Example:
CHECK_SCHEDULE 50 240: Check if a task that takes 50 time units can be completed before the 240th time unit.
