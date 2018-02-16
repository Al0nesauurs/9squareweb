import React from 'react'
import './style.css'

export class Login extends React.Component {
  constructor (props) {
    super(props)
    this.state = {
      username: '',
      password: ''
    }
    this.handleChange = this.handleChange.bind(this)
    this.handlePress = this.handlePress.bind(this)
  }

  handleChange (event) {
    if (event.target.name === 'User') {
      this.props.inputlog(event.target.value, this.props.exam.password)
    } else if (event.target.name === 'Pass') {
      this.props.inputlog(this.props.exam.username, event.target.value)
    }
  }

  handlePress (event) {
    event.which = event.which || event.keyCode
    if (event.which === 13) {
      this.props.loginfire(this.props.exam.username, this.props.exam.password, 'examiner')
    }
  }

  render () {
    return (
      <div id='wrapper'>
        <div ></div>
        <div className='log_in_content'>
          <p className='login_headerText'>EXAMINER Log In</p>
          <div style={ {marginTop: '24px'} }>
            <input type="text" className="form-input" placeholder="Phone number or email" style={ {width: '100%'} }name='User' onChange={this.handleChange} onKeyPress={this.handlePress}/>
            <div className='space'> </div>
            <input type="password" className="form-input" placeholder="Password" style={ {width: '100%'} } name='Pass' onChange={this.handleChange} onKeyPress={this.handlePress}/>
          </div>
          <button className='col-12 emailLoginBtn' onClick={ () => { this.props.loginfire(this.props.exam.username, this.props.exam.password,'examiner') } }><span className='loginBtn--text'>Log In</span></button>
          <p className='col-12 loginDivider'/>
          {/* <button className='col-12 loginBtn loginBtn--google' onClick={ () => { this.props.logingmail() } }><span className='loginBtn--text'>Continue with Google</span></button>
          <p className='col-12 loginDivider'/>
          <div className='col-12'><p className='guideText'>Don't have an account? <span><NavLink key='10' activeClassName='active' to='/register' id='signUpLink'>Sign Up</NavLink></span></p></div> */}
          <div className= 'guideText'>No account ? Please contact admin to get new account</div>
        </div>
        <div ></div>
      </div>
    )
  }
}
