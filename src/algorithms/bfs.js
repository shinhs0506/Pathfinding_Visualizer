class Bfs {
	constructor(graph, start, goal) {
		console.log('bfs')
		this.queue = []
		this.graph = graph
		this.start = start
		this.goal = goal

		this.queue.push([this.start])
	}

	solve(){
		let shortestPath = []
		let explored = []
		while(!this.isFrontierEmpty()){
			let path = this.dequeue();
			let isFinished = this.checkFinished(path);
			let curr =path[path.length - 1];
			explored.push(curr)
			if (isFinished){
				shortestPath = path;
				break;
			} else {
				let neighbours = this.getNeighbours(path);
				for (let n of neighbours) {
					let tmp = path.slice()
					tmp.push(n);
					this.enqueue(tmp)
					this.graph[n[0]][n[1]].isVisited = true;
				}		
			}
		}
		explored = explored.slice(1, explored.length-1);
		shortestPath = shortestPath.slice(1, shortestPath.length-1);
		return {explored, shortestPath};
	}

	enqueue(path) {
		this.queue.push(path);
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
			if (!this.outOfBound(tmp) && !this.graph[tmp[0]][tmp[1]].isWall && !this.graph[tmp[0]][tmp[1]].isVisited && !this.graph[tmp[0]][tmp[1]].isStart) {
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
