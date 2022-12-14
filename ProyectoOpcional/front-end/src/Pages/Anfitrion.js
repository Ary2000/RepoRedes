import React, { useState, useEffect } from "react";
import axios from "axios";
import { Chessboard } from "react-chessboard";
import { useParams } from "react-router-dom";

export const Anfitrion = (props) => {
  const mensajeDefault = "Su turno";
  const colorActivo = "green";
  const colorDesactivado = "red";
  const [mensaje, setMensaje] = useState(mensajeDefault);
  const [positions, setPositions] = useState({});

  const { idTablero } = useParams();

  // Carga las posiciones de las fichas en la tabla
  useEffect(() => {
    getBoard().then((actualPositions) => {
      setPositions(actualPositions);
    });
  }, []);
  // Revisa si el movimiento hecho es lega;
  async function onDrop(sourceSquare, targetSquare, piece) {
    let res = await axios.get(
      "http://127.0.0.1:31000/verificar/" + sourceSquare + "/" + targetSquare
    );
    if (res.data.res == "1") {
      let tempPositions = positions;
      delete tempPositions[sourceSquare];
      tempPositions[targetSquare] = piece;
      setPositions(tempPositions);
      return true;
    } else return false;
  }
  // Consigue los datos de la tabla en elasticsearch para poder cargar
  // las fichas bien
  async function getBoard() {
    let board = await axios
      .get("http://127.0.0.1:31000/searchBoardAnfitrion/" + idTablero)
      .then();
    let pieces = board.data.board.piece;
    let positionsTemp = {};
    pieces.forEach((piece, num) => {
      let typePiece = "";
      let positionPiece = "";
      if (piece.white) typePiece += "w";
      else typePiece += "b";
      switch (piece.piece) {
        case 0: {
          typePiece += "P";
          break;
        }
        case 1: {
          typePiece += "B";
          break;
        }
        case 2: {
          typePiece += "N";
          break;
        }
        case 3: {
          typePiece += "R";
          break;
        }
        case 4: {
          typePiece += "Q";
          break;
        }
        case 5: {
          typePiece += "K";
          break;
        }
      }
      switch (piece.column) {
        case 1: {
          positionPiece += "a";
          break;
        }
        case 2: {
          positionPiece += "b";
          break;
        }
        case 3: {
          positionPiece += "c";
          break;
        }
        case 4: {
          positionPiece += "d";
          break;
        }
        case 5: {
          positionPiece += "e";
          break;
        }
        case 6: {
          positionPiece += "f";
          break;
        }
        case 7: {
          positionPiece += "g";
          break;
        }
        case 8: {
          positionPiece += "h";
          break;
        }
      }
      positionPiece += piece.row.toString();
      positionsTemp[positionPiece] = typePiece;
    });
    return positionsTemp;
    // setPositions(positionsTemp);
  }

  return (
    <div
      style={{
        display: "flex",
        flex: "1000",
      }}
    >
      <Chessboard onPieceDrop={onDrop} position={positions} />
      <div
        style={{
          display: "block",
          justifyContent: "center",
          alignItems: "center",
          padding: 20,
        }}
      >
        {/* https://daveceddia.com/usestate-hook-examples/ */}
        <h1
          style={{
            color: `${colorActivo}`,
          }}
        >
          {mensaje}
        </h1>
        <button
          style={{
            width: "70px",
            height: "50px",
          }}
        >
          Buscar partida
        </button>
      </div>
    </div>
  );
};
