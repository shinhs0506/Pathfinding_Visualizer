import Algorithm from './algorithm.js'

class Dfs extends Algorithm {
	constructor(graph, start, goal){
		super(graph, start, goal)
	}

	enqueue(path) {
		this.orderingStructure.push(path)
	}

	dequeue() {
		return this.orderingStructure.pop();
	}
}

export default Dfs
