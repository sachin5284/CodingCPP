import React from 'react';
const Picture = (props) => {
  return (
    <div className='picture'>
      <img alt="" src={props.src} className='picture'/>
      {props.children}
    </div>
  )
}
export default Picture;