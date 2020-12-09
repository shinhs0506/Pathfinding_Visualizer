import React, { Component } from 'react'
import ButtonGroup from 'react-bootstrap/ButtonGroup'

import MenuButton from './menuButton'
import MenuDropButton from './menuDropButton'


class Menubar extends Component {
	constructor(props) {
		super(props);
		this.state = {
			startBtn: 'start',
			helpBtn: 'help',
			algorithmBtn: 'algorithm',
			clearBtn: 'clear',
			resetBtn: 'reset'
		};
	}

	render() {
		return (
			<ButtonGroup>
				<MenuButton variant='success' name={this.state.startBtn} />
				<MenuButton variant='info' name={this.state.helpBtn} />
				<MenuDropButton variant='primary' name={this.state.algorithmBtn} items={['bfs', 'dfs']} />
				<MenuButton variant='warning' name={this.state.clearBtn} />
				<MenuButton variant='danger' name={this.state.resetBtn} />
			</ButtonGroup>
		);
	}
}

export default Menubar
