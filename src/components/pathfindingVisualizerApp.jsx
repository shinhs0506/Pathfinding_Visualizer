import React, { Component } from 'react'
import Container from 'react-bootstrap/Container'
import Row from 'react-bootstrap/Row'

import Menubar from './menuBar.jsx'
import Board from './board.jsx'



class PathfindingVisualizerApp extends Component {
	constructor(props) {
		super(props);
		this.state = {
			
		};
	}	
	
	render() {
		return (
			<Container fluid='sm'>
				<h1>Pathfinding Visualizer</h1>
				<Menubar />
				<Board />
			</Container>
		);
	}
}

export default PathfindingVisualizerApp
