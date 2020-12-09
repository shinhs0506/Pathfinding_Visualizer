import React, { Component } from 'react'

class Board extends Component {
	constructor(props) {
		super(props)
		this.canvasRef = React.createRef()
		this.state = {
			
		}
	}
	
	componentDidMount() {
		const canvas = this.canvasRef.current;
		const context = canvas.getContext('2d');
		context.canvas.width = window.innerWidth;
		context.canvas.height = window.innerHeight;
		context.fillRect(0, 0, canvas.width, canvas.height);
	}


	render() {
		return(
			<div>
				<canvas ref={this.canvasRef} />
			</div>
		); 
	}
}

export default Board
