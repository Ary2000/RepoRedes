import React from "react";
import { Chessboard } from "react-chessboard";

export const CrazyBoard = ({ tipoUsuairo }) => {
  if (tipoUsuairo == 0) return <Chessboard />;
};
