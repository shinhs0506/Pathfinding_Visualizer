class Bfs {
	constructor(graph, start, goal) {
		console.log('bfs')
		this.queue = []
		this.graph = graph
		this.start = start
		this.goal = goal

		this.queue.push([this.start])
	}


	enqueue(path) {
		this.queue.push(path);
		return path[path.length - 1]
	}

	dequeue() {
		return this.queue.shift();
	}

	isFrontierEmpty() {
		return this.queue.length === 0;
	}

	checkFinished(path) {
		let last = path[path.length - 1];
		return (last[0] === this.goal[0]) && (last[1] === this.goal[1]);
	}

	getNeighbours(path) {
		let res = [];
		let last = path[path.length - 1];
		// up, right, down, left
		let directions = [[-1, 0], [0, 1], [1, 0], [0, -1]];
		for (let d of directions){
			let tmp = last.slice();
			tmp[0] += d[0];
			tmp[1] += d[1];
			if (!this.outOfBound(tmp) && (this.graph[tmp[0]][tmp[1]] === 0 || this.graph[tmp[0]][tmp[1]] === 3)){
				res.push(tmp);	
			}
		}
		return res;
	}
	
	outOfBound(cell){
		return cell[0] < 0 || cell[1] < 0 || this.graph.length <= cell[0] || this.graph[0].length <= cell[1]
	}

}

export default Bfs
