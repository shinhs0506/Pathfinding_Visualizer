import React, { Component } from 'react'

class Menubar extends Component {
	constructor(props) {
		super(props);
		this.state = {
			items: ["start", "algorithm"]
		};
	}

	render() {
		return (
			<div>
				<p>Menu</p>
			</div>
		);
	}
}

export default Menubar
