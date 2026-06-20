import fastify from "fastify";

const app = fastify({
  logger: true,
  ajv: {
    customOptions: {
      coerceTypes: false,
    },
  },
});

app.get("/", async (_, reply) => {
  reply.code(200).send({ message: "OK" });
});

app.post<{ Body: { title: string } }>(
  "/",
  {
    schema: {
      body: {
        type: "object",
        required: ["title"],
        properties: {
          title: { type: "string", minLength: 1 },
        },
      },
    },
  },
  async (request, reply) => {
    const { title } = request.body;
    reply.code(201).send({ title });
  },
);

export default app;
