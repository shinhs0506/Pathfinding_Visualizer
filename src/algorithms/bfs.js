import Algorithm from './algorithm.js'

class Bfs extends Algorithm {	
	constructor(graph, start, goal){
		super(graph, start, goal)
	}

	enqueue(path) {
		this.orderingStructure.push(path);
	}

	dequeue() {
		return this.orderingStructure.shift();
	}

}

export default Bfs

