
//Avoid Busy Waiting

//BUSY Waiting: You have busy waiting , When one thread waits for a result from another thread

//1 Poor Soulution : Sleep
while (waitingForThread1() && waitingForThread2())
{
    Thread.sleep(1000) // sleep for 1 second
}

/*Problem here is wasting CPU cycles by repeadly checking the condition

There are still some draw backs to this pattern:

You’re still wasting cycles. It may seem like you’re wasting one cycle every
second. However, every time the thread wakes up it has to reload the thread’s stack, registers, and it has to recompute if the other thread is done. There’s still significant wastage.
How do you set the sleep duration?
Set it too long, and there is a long delay between the threads finishing and
the main thread recognizing that it’s done
Set it too short, and you increase the amount of wasted cycles
*/


//2 Better but still poor solution : Exponential Backoff

private static final int MAX_BACKOFF=1000*60*60; // 1 hour
private static final int INITIAL_BACKOFF=100; // 100ms
int backOff=INITIAL_BACKOFF;
while( waitinigForThread1() && waitingForThread2() ) {
    Thread.sleep(backOff); // Sleep for 1 second
    backOff=backOff<<2; //bit shift to the left to multiply by 2
    if(backOff < MAX_BACKOFF) {
        backOff = MAX_BACKOFF;
    }
}

/*
 isn’t the best possible solution yet for a couple of reasons:

Ideally we want the the main thread to wake up only once or twice
Once when the first sub task completes
A second time when the second sub tasks completes
We still have to play with the starting back off, and max back off parameters to get decent performance
*/


