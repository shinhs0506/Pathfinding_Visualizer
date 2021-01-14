import React, { Component } from 'react'
import Container from 'react-bootstrap/Container'
import Row from 'react-bootstrap/Row'
import ButtonGroup from 'react-bootstrap/ButtonGroup'
import Button from 'react-bootstrap/Button'

import './pathfindingVisualizerApp.css';

import Cell from './cell/cell.jsx'

import AlgorithmFactory from '../algorithms/algorithmFactory.js'


class PathfindingVisualizerApp extends Component {
	constructor(props) {
		super(props);
		
		this.initStartR = 3;
		this.initStartC = 4;
		this.initFinishR = 20;
		this.initFinishC = 18;

		this.state = {
			algorithms: ['bfs', 'dfs'],
			algorithm: 'bfs',
			grid: [],
			start: [this.initStartR, this.initStartC],
			finish: [this.initFinishR, this.initFinishC],
		};
		this.handleAlgorithmChange = this.handleAlgorithmChange.bind(this);
		
		this.handleStart = this.handleStart.bind(this);
		this.handleClear = this.handleClear.bind(this);
		this.handleReset = this.handleReset.bind(this);
		this.handleMouseDown = this.handleMouseDown.bind(this);
	}	

	componentDidMount() {
		let w = 25;
		let h = 25;
		let initialGrid = [];
		for (let row=0; row < h; row++){
			let tmp = []
			for (let col=0; col < w; col++){
				let cell = {
						isStart: (row === this.state.start[0]) && (col === this.state.start[1]),
						isFinish: (row === this.state.finish[0]) && (col === this.state.finish[1]),
						isWall: false,
						isVisited: false
					}
				tmp.push(cell);
			}
			initialGrid.push(tmp);
		}
		this.setState({grid: initialGrid});
	}
	
	handleAlgorithmChange(e){
		this.setState({
			algorithm: e.target.value
		});
	}

	handleStart() {
		let algorithmFactory = new AlgorithmFactory();
		let algo = algorithmFactory.createAlgorithm(this.state.algorithm, this.state.grid, this.state.start, this.state.finish)
		let {explored, shortestPath} = algo.solve()
		let promises = []
		for (let i = 0; i < explored.length; i++){
			let p = new Promise((resolve, reject) => {
			setTimeout(() => {
				document.getElementById('cell-'+explored[i][0]+'-'+explored[i][1]).className = 'cell cell-visited';
				resolve()
				}, 20 * i);
			});
			promises.push(p);
		}
		Promise.all(promises).then(() => {
			for (let j = 0; j < shortestPath.length; j++){
				setTimeout(() => {
				document.getElementById('cell-'+shortestPath[j][0]+'-'+shortestPath[j][1]).className = 'cell cell-path';
				}, 20 * j);
			}
		});
	}

	handleClear() {
		let newGrid = this.state.grid.slice();
		for (let i = 0; i < newGrid.length; i++){
			for (let j = 0; j < newGrid[0].length; j++){
				newGrid[i][j].isVisited = false;
				let element = document.getElementById('cell-'+i+'-'+j);
				if (element.className === 'cell cell-visited' || element.className === 'cell cell-path') {
					element.className = 'cell'
				}
			}
		}
		this.setState({grid: newGrid})
	}

	handleReset() {
		this.handleClear()
		let newGrid = this.state.grid.slice();
		for (let i = 0; i < newGrid.length; i++){
			for (let j = 0; j < newGrid[0].length; j++){
				newGrid[i][j].isWall = false;
			}
		}
		this.setState({grid: newGrid})
	}

	handleMouseDown(row, col) {
		let newGrid = this.state.grid.slice();
		let cell = newGrid[row][col];
		let newCell = {
			...cell,
			isWall: !cell.isWall,
		}
		newGrid[row][col] = newCell;
		console.log(row, col, newCell)
		this.setState({grid: newGrid})
	}

	render() { 
		let grid = this.state.grid
		return (
			<Container>
				<Row>
					<h1>Pathfinding Visualizer</ h1>
				</ Row>
				{this.state.algorithms.map((algo) => (
					<Row key={'row_'+algo}>
					<label key={'label_'+algo}>
						<input type='radio' value={algo} checked={this.state.algorithm === algo} onChange={this.handleAlgorithmChange} />
						{algo}	
					</ label>
					</ Row>
				))}
				<Row>
					<ButtonGroup>
						<Button onClick={this.handleStart}>Start</ Button>
						<Button onClick={this.handleClear}>Clear</ Button>
						<Button onClick={this.handleReset}>Reset</ Button>
					</ ButtonGroup>
				</ Row>
				<Row>
					<div className='grid'>
						{grid.map((row, i) => {
							return (
								<div key={i} className='row' >
									{row.map((cell, j) => {
										let { isStart, isFinish, isWall, isVisited } = cell;
										return (
										<Cell
											key={i+'_'+j}
											row={i}
											col={j}
											isStart={isStart}
											isFinish={isFinish}
											isWall={isWall}
											isVisited={isVisited}
											onMouseDown={(row, col) => this.handleMouseDown(i, j)}>
										</ Cell>
										)
									})}
								</ div>
							)
						})}
					</ div>
				</ Row>
			</ Container>
		);
	}
}

export default PathfindingVisualizerApp
