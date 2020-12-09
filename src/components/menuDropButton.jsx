import React, { Component } from 'react'
import DropdownButton from 'react-bootstrap/DropdownButton'
import Dropdown from 'react-bootstrap/Dropdown'

class MenuDropButton extends Component {
	constructor(props) {
		super(props)
		this.state = {
			name: props.name,
			items: props.items
		}
	}	
	
	render() {
		return (
			<DropdownButton id="dropdown-basic-button" title={ this.state.name }>
				{this.state.items.map((item) => 
					<Dropdown.Item key={ item }>{ item }</Dropdown.Item>
				)}
			</DropdownButton>
		)
	}
}

export default MenuDropButton
