import React, { Component } from 'react'
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
			<div>
				<h1>Helllo World</h1>
				<Menubar />
				<Board />
			</div>
		);
	}
}

export default PathfindingVisualizerApp
