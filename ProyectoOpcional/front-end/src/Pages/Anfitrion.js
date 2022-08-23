import React, { useState } from "react";
import axios from "axios";
import { Chessboard } from "react-chessboard";
import { useParams } from "react-router-dom";

export const Anfitrion = () => {
  const mensajeDefault = "Su turno";
  const colorActivo = "green";
  const colorDesactivado = "red";
  const [mensaje, setMensaje] = useState(mensajeDefault);

  const { idTablero } = useParams();
  async function onDrop(sourceSquare, targetSquare) {
    let resultado = await axios.get("http://127.0.0.1:80/members").then();
    console.log(idTablero);
    return false;
  }

  return (
    <div
      style={{
        display: "flex",
        flex: "1000",
      }}
    >
      <Chessboard onPieceDrop={onDrop} />
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
