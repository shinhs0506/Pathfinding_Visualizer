import Bfs from './bfs.js'
import Dfs from './dfs.js'

class AlgorithmFactory {
	createAlgorithm(algorithm, graph, start, finish){
		let algo = null;
		if (algorithm === 'bfs'){
			algo = new Bfs(graph, start, finish)
		} else if (algorithm === 'dfs'){
			algo = new Dfs(graph, start, finish)
		}
		return algo;
	}
}

export default AlgorithmFactory
