import java.util.*;

/**
 * Generic version of the MyQueue class.
 * @param <T> the type of the value being queued
 */

class MyQueue <T> {
	private T[] queue;	// array for queue elements
	private int front, // one counterclockwise from front
	            rear, 	// array position of rear element
				capacity;	// capacity of queue array

	/**
	 * Create an empty queue whose initial capacity is cap
	 */
	@SuppressWarnings("unchecked")
	MyQueue(int cap) {
		capacity = cap;
		queue = (T []) new Object [capacity];
		front = rear = 0;
	}

	/** 
	 * If number of elements in the queue is 0, return true else return false
	 */
	boolean IsEmpty() {

		// NEED TO IMPLEMENT
		return front == rear;
	}

	/**
	 * Add x at rear of queue
	 */
	void Push (T x) throws Exception { 

// NEED TO IMPLEMENT

		// if queue full, throw the following message
		if((rear+1) % capacity == front)
			throw new Exception ("Queue is Full");
		
		rear = (rear + 1) % capacity;
		queue[rear] = x;

	}

	/**
	 * Delete front element from queue
	 */
	T Pop() throws Exception {
		// if queue is empty, throw the following message
		if(IsEmpty())
			throw new Exception("Queue is empty. Cannot delete.");

// NEED TO IMPLEMENT
		T temp = queue[front];
		front = (front+1) % capacity;

		return temp;
	}
	
	public String toString() {
		String a = new String();

		a = "Queue : " ;
		

		// NEED TO IMPLEMENT
		int temp = front;
		while(temp != rear)
		{
			a += queue[(temp+1)%capacity] + " ";
			temp++;
			temp %= capacity;
		}

		a += "\n";
		a += "rear="+rear+", "+"front="+front;


		return a;
	}
}; 


