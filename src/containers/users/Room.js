import React from 'react'
import * as firebase from 'firebase'
import { connect } from 'react-redux'
import { bindActionCreators } from 'redux'
import  { Room } from '../../components/users/Room/Room.js'
import { inputreg } from '../../actions/input.js'
import { regisfire } from '../../actions/user.js'
import { showDevice, addDevice, setActive, delDevice, setDeviceActive, getRoomNum } from '../../actions/test.js'
import {NavLink, Link} from 'react-router-dom'

class RoomContainer extends React.Component {
  componentWillMount() {
    let that = this
    let arr = []
    let i = 0 
    firebase.auth().onAuthStateChanged(function(user) {
      if (user) {
        that.props.showDevice(arr)          
      }
    })
  }
  render () {
    let i = 0
    let that = this
    let device = []
    let content = ''
    if (firebase.auth().currentUser)
    {
      content = (
        <div>
          <Room {...this.props} />
        </div>
        )
      firebase.database().ref('/rooms/room'+this.props.test.num+'/devices/').once('value', function (snapshot) {
        snapshot.forEach(function (childSnapshot) {
          const DeviceBtn = childSnapshot.val().ava ? 'DeviceAvaBtn' : 'DeviceNotAvaBtn'          
          device[i] = (
            <div className='col-8' key={i}>
              <div className='payment_itemDiv--mid'>
                <span><Link to ={'/test/room'+that.props.test.num+'/device'+childSnapshot.val().num}>
                <p className='col-12'/>
                  <div className={DeviceBtn}> Device:{childSnapshot.val().num}: {childSnapshot.val().ava+' '}</div> 
                </Link>

                  </span>
                </div>
                {/* <div className='payment_itemDiv--after' onClick={() => { that.props.deletepay(id, room, i) } }><img src={delBtn} alt=''/></div> */}
              </div>
            )
          i++
        })
      }).then(() => {
        this.props.showDevice(device)
      })
    } else {
      content = (
        <div>
          Loading . . .
        </div>
      )
    }
    return content    
  }
}
const mapStateToProps = (state) => {
  return {
    exam: state.exam,
    test: state.test
  }
}

const mapDispatchToProps = (dispatch) => {
  return bindActionCreators(
    {
      inputreg, regisfire, showDevice, addDevice, setActive, delDevice, setDeviceActive
    }, dispatch)
}
export default connect(mapStateToProps, mapDispatchToProps)(RoomContainer)
