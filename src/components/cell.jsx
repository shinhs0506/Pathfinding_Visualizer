import React, { Component } from 'react'

class Cell extends Component {
	constructor(props) {
		super(props)
		this.state = {
		
		}
	}

	render() {
		let colour = this.props.value ? 'grey' : 'white'
		return (
			<td 
				style={{
					overflow: 'hidden',
					width: '25px',
					height: '25px',
					backgroundColor: '#e4e4a1',
					color: 'red',
					boardColor: 'black',
					border: '.5px solid black'
				}}
			onClick={this.props.handleClick}	>
				<div
					style={{
						color: colour,
						border: '1px solid',
						backgroundColor: colour,
						borderColor: colour,
						height:25}} />
			</td>	

		);
	}
}

export default Cell
