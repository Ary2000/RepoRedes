import React from "react";
import { Chessboard } from "react-chessboard";

export const Invitado = () => {
  function onDrop(sourceSquare, targetSquare) {
    return false;
  }

  return <Chessboard boardOrientation="black" onPieceDrop={onDrop} />;
};
