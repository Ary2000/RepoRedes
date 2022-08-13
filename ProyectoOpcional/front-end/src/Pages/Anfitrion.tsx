import React from 'react'
import { Chessboard } from 'react-chessboard'

export const Anfitrion = () => {

  function onDrop() {
    return false;
  }

  return (
    <Chessboard onPieceDrop={onDrop}/>
  )
}
