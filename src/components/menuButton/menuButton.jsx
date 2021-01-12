import React, { Component } from 'react'
import Button from 'react-bootstrap/Button'

class MenuButton extends Component {
	constructor(props) {
		super(props)
		this.state = {
			variant: props.variant,
			name: props.name
		}
	}

	render(){
		let n = this.state.name;
		return (
			<Button variant={ this.state.variant } onClick={() => this.props.handleButtonClick(n)}>{ this.state.name }</Button>
		);
	}
}

export default MenuButton

