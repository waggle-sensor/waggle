function linked_list()
{
	//create_node reserves space and populates a new node
	linked_list.create_node = function(name, lat, lng, active, page) {
		var node = {node_name: name, lat: lat, lng: lng, active: active, page: page, next: null};
		return node;
	};

	this.start = null;
	this.end = null;

	//add_node creates, populates, and places a node alphabetically within the list
	this.add_node = function(name, lat, lng, active, page) {
		var idx = 0;

		if(this.start === null) {
			this.start = linked_list.create_node(name, lat, lng, active, page);
			this.end = this.start;
			return idx;
		}
		else {
			//find the location to place the new node and create it (Sort the linked list)
			var cur_node = this.start;
			var prev_node = this.start;

			if(cur_node.node_name.toLowerCase() > name.toLowerCase()) {
				this.start = linked_list.create_node(name, lat, lng, active, page);
				this.start.next = cur_node;
				return idx;
			}

			while(cur_node.node_name.toLowerCase() <= name.toLowerCase()) {
				prev_node = cur_node;
				cur_node = cur_node.next;
				idx++;

				if(cur_node === null) {
					cur_node = linked_list.create_node(name, lat, lng, active, page);
					prev_node.next = cur_node;
					this.end = cur_node;
					return idx;
				}
			}
			prev_node.next = linked_list.create_node(name, lat, lng, active, page);
			prev_node.next.next = cur_node;
			return idx;
		}
	};

	//delete_node removes a node with a given name from the list
	this.delete_node = function(name) {
		var cur_node = this.start;
		var prev_node = this.start;

		while(cur_node !== null) {
			if(cur_node.node_name === name) {
				if(cur_node === this.start) {
					this.start = cur_node.next;
					return;
				}
				if(cur_node === this.end) {
					this.end = prev_node;
					prev_node.next = cur_node.next;
					return;
				}
				else {
					prev_node.next = cur_node.next;
					cur_node.next = null;
				}
			}
			prev_node = cur_node;
			cur_node = cur_node.next;
		}
	};

	//Find the index of a node in the list given its name
	this.at = function(name) {
		var cur_node = this.start;
		var idx = 0;

		while(cur_node != null) {
			if(cur_node.node_name === name) {
				return idx;
			}
			cur_node = cur_node.next;
			idx++;
		}
		return -1;
	};

	/* Updates the linked list with new data from a 2D array
	 * Returns 2D array holding modified nodes: 0-updated node,
	 *										    1-added node,
	 *										    2-deleted node
	 */
	this.list_update = function(array) {
		var cur_node = this.start;
		var prev_node = this.start;

		var idx = 0;
		var add_idx = 0;

		var update = false;
		var delete_match = false
		var add_match = true;
		var added = true;

		var update_array = [];
		var update_idx = 0;

console.log("In update_list...Here is 'array': "+array.length);
	for(var k = 0; k < array.length; k++) {
		console.log("name: "+array[k].node_name+" idx: "+k);
	}

		//Delete nodes if they don't exist in array or update them if they do
		while(cur_node != null) {
			update = false;
			delete_match = true;
			for(var i = 0; i < array.length; i++) {
				if(cur_node.node_name === array[i].node_name) {
					delete_match = false;
					//Update node if necessary
					if(cur_node.lat != array[i].lat) {
						update = true;
						cur_node.lat = array[i].lat;
					}
					if(cur_node.lng != array[i].lng) {
						update = true;
						cur_node.lng = array[i].lng;
					}
					if(cur_node.active != array[i].active) {
						update = true;
						cur_node.active = array[i].active;
					}
					if(cur_node.page != array[i].page) {
						update = true;
						cur_node.page = array[i].page;
					}
					if(update) {
						update_array.push([]);
						update_array[update_idx].push(idx);
						update_array[update_idx].push(0);
						update_array[update_idx].push(cur_node.node_name);
						update_idx++;
					}
				}
			}
			if(delete_match) {
				prev_node = cur_node;
				cur_node = cur_node.next;

				this.delete_node(prev_node.node_name);

				update_array.push([]);
				update_array[update_idx].push(idx);
				update_array[update_idx].push(2);
				update_array[update_idx].push("");
				update_idx++;
				idx--;
			}
			else {
				prev_node = cur_node;
				cur_node = cur_node.next;
			}
			idx++;
		}

		//Add nodes if they don't exist in list
		for(var j = 0; j < array.length; j++) {
			add_match = true;
			cur_node = this.start;
			while(cur_node != null) {
				if(cur_node.node_name === array[j].node_name) {
					add_match = false
					break;
				}
				prev_node = cur_node;
				cur_node = cur_node.next;
			}

			if(add_match) {
				add_idx = this.add_node(array[j].node_name, array[j].lat, array[j].lng, array[j].active, array[j].page);

				update_array.push([]);
				update_array[update_idx].push(add_idx);
				update_array[update_idx].push(1);
				update_array[update_idx].push(array[j].node_name);
				update_idx++;
			}
		}

		//TEST for the returned array
		test_node = this.start;
		console.log("At end of update_list...Here is the list: ")
		while(test_node != null) {
			console.log("updated list name: "+test_node.node_name);
			test_node = test_node.next;
		}
		return update_array;
	};

	//these functions return their respective elements given an index to the list
	this.get_node_name = function(node_idx) {
		var idx = 0;

		if(this.start === null) {
			return "Error";
		}
		else {
			var cur_node = this.start;

			while(idx != node_idx) {
				if(cur_node == null) {
					return "Error";
				}
				cur_node = cur_node.next;
				idx++;
			}
			return cur_node.node_name;
		}
	};

	this.get_lat_lng = function(node_idx) {
		var idx = 0;

		if(this.start === null) {
			return "Error";
		}
		else {
			var cur_node = this.start;

			while(idx != node_idx) {
				if(cur_node == null) {
					return "Error";
				}
				cur_node = cur_node.next;
				idx++;
			}
			var array = [cur_node.lat, cur_node.lng];
			return array;
		}
	};

	this.get_status = function(node_idx) {
		var idx = 0;

		if(this.start === null) {
			return "Error";
		}
		else {
			var cur_node = this.start;

			while(idx != node_idx) {
				if(cur_node == null) {
					return "Error";
				}
				cur_node = cur_node.next;
				idx++;
			}
			return cur_node.active;
		}
	};

	this.get_page = function(node_idx) {
		var idx = 0;

		if(this.start === null) {
			return "Error";
		}
		else {
			var cur_node = this.start;

			while(idx != node_idx) {
				if(cur_node == null) {
					return "Error";
				}
				cur_node = cur_node.next;
				idx++;
			}
			return cur_node.page;
		}
	};
}