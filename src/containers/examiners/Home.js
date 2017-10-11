import React from 'react'
import { connect } from 'react-redux'
import { bindActionCreators } from 'redux'
import  { Home } from '../../components/examiners/Home/Home.js'
// import {
//   LoginForm
// } from '../components'
export class ExHomeContainer extends React.Component {

  render () {
    return (
      <div>
        <Home {...this.props} />
      </div>
    )
  }
}
const mapStateToProps = (state) => {
//   return {
//     user: state.user
//   }
}

const mapDispatchToProps = (dispatch) => {
//   return bindActionCreators(
//     {
//       thelogin, googlelogin, facelogin, twitterlogin, firebaselogin
//     }, dispatch)
}
export default connect(mapStateToProps, mapDispatchToProps)(ExHomeContainer)
