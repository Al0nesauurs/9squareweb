import React from 'react'
import {NavLink} from 'react-router-dom'
import './style.css'

export class Test extends React.Component {
  constructor (props) {
    super(props)
    this.state = {
      room: []
    }
    this.handleChange = this.handleChange.bind(this)
  }

  handleChange (event) {
    if (event.target.name === 'User') {
      this.props.inputlog(event.target.value, this.props.user.password)
    } else if (event.target.name === 'Pass') {
      this.props.inputlog(this.props.user.username, event.target.value)
    }
  }

  render () {
    return (
      <div id='home_wrapper'>
        <div id="header">การทดสอบ</div>
        <div id="main-wrap">
            <div id="sidebar" className="header_content">
            </div>
            <div id="content-wrap">
            {this.props.test.room}
            </div>
        </div>
        <div id="footer">Footer</div>
      </div>   
    )
  }
}