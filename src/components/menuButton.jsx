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
		return (
			<Button variant={ this.state.variant }>{ this.state.name }</Button>
		);
	}
}

export default MenuButton

