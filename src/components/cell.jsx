import React, { Component } from 'react'

class Cell extends Component {
	constructor(props) {
		super(props)
		this.state = {
		
		}
	}


	render() {
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
				}}>
				<div
					style={{
						color: 'blue',
						border: '1px solid',
						backgroundColor: 'blue',
						borderColor: 'blue',
						height:25}} />
			</td>	

		);
	}
}

export default Cell
