function queue() {
	//Global variables for the queue
	this.start = null;
	this.end = null;
	this.data = 0;
	var size = 0;

	queue.node = function(data) {
		var node ={data: data, next: null};
		return node;
	}

	this.enqueue = function(data) {
		if(this.start == null) {
			this.start = queue.node(data);
			this.end = this.start;
		}
		else if(size == 60) {
			//Release the oldest value and continue
			this.start = this.start.next;
		}
		
		this.end.next = queue.node(data);
		this.end = this.end.next;
		size++;
	}

	this.dequeue = function() {
		var tmp = this.start;
		this.start = this.start.next;
		size--;
		return tmp.data;
	}
}