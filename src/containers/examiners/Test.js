import React from 'react'
import * as firebase from 'firebase'
import { connect } from 'react-redux'
import { bindActionCreators } from 'redux'
import  { Test } from '../../components/examiners/Test/Test.js'
import { inputreg } from '../../actions/input.js'
import { regisfire } from '../../actions/user.js'
import { showroom, addroom, setActive, delRoom, getRoomNum } from '../../actions/test.js'
import { Link } from 'react-router-dom'
import './style.css'
class ExTestContainer extends React.Component {
  componentWillMount() {
    let that = this
    let arr = []
    firebase.auth().onAuthStateChanged(function(user) {
      if (user) {
        that.props.showroom(arr)          
      }
    })
  }
  render () {
    let i = 0
    let that = this
    let room = []
    let content = ''
    if (firebase.auth().currentUser)
    {
      content = (
        <div>
          <Test {...this.props} />
        </div>
      )
      firebase.database().ref('/rooms/').once('value', function (snapshot) {
        snapshot.forEach(function (childSnapshot) {
          const TestBtn = childSnapshot.val().ava ? 'RoomAvaBtn' : 'RoomNotAvaBtn'   
          room[i] = (
            <div key={i}>
              <div>
                <span><Link to ={'/examiner/test/room'} onClick={()=> {
                  that.props.getRoomNum(childSnapshot.val().num)
                }}>
                  <div className={TestBtn}> Room:{childSnapshot.val().num}: {childSnapshot.val().ava+' '}</div> 
                </Link>
                <div className="buttonSet">
                  <button onClick={()=> {
                    that.props.setActive(childSnapshot.val().num)
                  }} > Active/Inactive</button>
                  <button onClick={()=> {
                    let answer = window.confirm('WARNING! You are deleting room ' + childSnapshot.val().num + ' Continue?')
                    if (answer) {
                      that.props.delRoom(childSnapshot.val().num)
                    }
                  }}> Delete room </button>
                </div>
                </span>
              </div>
              {/* <div className='payment_itemDiv--after' onClick={() => { that.props.deletepay(id, room, i) } }><img src={delBtn} alt=''/></div> */}
            </div>
          )
          i++
        })
      }).then(() => {
        this.props.showroom(room)
      })
    } else {
      content = (
        <div className="loader"></div>
      )
    }
    return content    
  }
}
const mapStateToProps = (state) => {
  return {
    test: state.test
  }
}

const mapDispatchToProps = (dispatch) => {
  return bindActionCreators(
    {
      inputreg, regisfire, showroom, addroom, setActive, delRoom, getRoomNum
    }, dispatch)
}
export default connect(mapStateToProps, mapDispatchToProps)(ExTestContainer)
